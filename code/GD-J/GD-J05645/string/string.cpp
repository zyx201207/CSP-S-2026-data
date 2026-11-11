#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0,si=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
		si+=a[i];
	}
	long long h_si=si/2;
	long long i=1,j=n,i1=0,j1=0;
	while(1){
		bool b=0;
		i1+=a[i];
		j1+=a[j];
		if(c[i]!=c[j]){
			b=1;
			if(i1>=j1)ans+=a[i];
			else ans+=a[j];
		}
		if(i1>h_si){
			if(b==1)ans-=(i1-h_si);
			break;
		}
		if(j1>h_si){
			if(b==1)ans-=(j1-h_si);
			break;
		}
	}
	cout<<ans;
	return 0;
}
