#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long deg[200005];
	char ch[200005];
	long long ans=0;
	for(long long i=1;i<=n;++i){
		cin>>deg[i]>>ch[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(deg[l]>deg[r]){
			deg[l]-=deg[r];
			if(ch[l]!=ch[r]){
				ans+=deg[r];
			}
			r--;
		}else if(deg[l]<deg[r]){
			deg[r]-=deg[l];
			if(ch[l]!=ch[r]){
				ans+=deg[l];
			}
			l++;
		}else{
			if(ch[l]!=ch[r]){
				ans+=deg[l];
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
