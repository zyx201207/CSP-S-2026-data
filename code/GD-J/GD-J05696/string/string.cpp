#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char s[N];
int n;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int i=1,j=n;
	while(i<=j){
		if(s[i]!=s[j]){
			ans+=min(a[i],a[j]);
		}
		if(a[i]>a[j]){
			a[i]-=a[j];
			j--;
		}else if(a[j]>a[i]){
			a[j]-=a[i];
			i++;
		}
		else{
			i++,j--;
		}
	}
	cout<<ans<<endl;
	return 0;	
}

