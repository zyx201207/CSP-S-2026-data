#include<bits/stdc++.h>
using namespace std;
int n,a[10005];
int ans=0,z=0;
string c[100005],s,d;
int main(){
	freopen("stringin","r","stdin");
	freopen("stringout","w","stdout");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
			if(c[i]=="c"){
				ans+=a[i]+1;
				c[i]="a";
			}
		}
		z=+a[i];
	}
	for(int i=1;i<=n;i++){
		s=c[i];
		for(int j=1;j<=a[i];j++){
			d=c[z=i];
		}
		if(s!=d){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
