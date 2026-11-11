#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a;
	char c;
}f[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> f[i].a >> f[i].c;
	}
	int l=1,r=n,ans=0;
	int lshu=f[1].a,rshu=f[n].a;
	while(l<r){
		if(lshu==0&&rshu==0&&l+1==r&&n%2==0) break;
		if(lshu==0){
			l++;
			lshu=f[l].a;
		}
		if(rshu==0){
			r--;
			rshu=f[r].a; 
		}
		if(f[l].c!=f[r].c){
			if(lshu>=rshu){
				lshu-=rshu;
				ans+=rshu;
				rshu=0;
			}
			else{
				rshu-=lshu;
				ans+=lshu;
				lshu=0;
			}
		}
		else{
			if(lshu>=rshu){
				lshu-=rshu;
				rshu=0;
			}
			else{
				rshu-=lshu;
				lshu=0;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

