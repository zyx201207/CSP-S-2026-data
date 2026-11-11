#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,id=1;
	long long ans=0,x;
	char y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(id!=1&&c[id-1]==y){
			a[id-1]+=x;
		}else{
			a[id]=x;
			c[id]=y;
			id++;
		}
	}
	id--;
	int i=1,j=id;
	while(i<j){
		//cout<<a[i]<<' '<<a[j]<<endl<<c[i]<<' '<<c[j]<<endl;
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
			a[i]-=min(a[i],a[j]);
			a[j]-=min(a[i],a[j]);
			if(!a[i])i++;
			if(!a[j])j--;
		}
	}
	cout<<ans;
	/*3
	2 a
	2 b
	1 c*/
	//cout<<b.size()<<endl<<b<<endl;
	return 0;
}
