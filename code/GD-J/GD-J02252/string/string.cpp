#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int ct;
	char v;
}e[200010];
int n,ans;
bool check(char a,char b){
	 return a==b;
	
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>e[i].ct>>e[i].v;
		
	}
	int exed=0,i=1,j=n;
	
	while (1){
		if (i>=j) break;
		if (e[i].ct==e[j].ct && exed==0){
			if (!check(e[i].v,e[j].v)) ans+=e[i].ct;
			i++,j--;
		}
		
		else{
			int ti=i,tj=j;
			if (!check(e[ti].v,e[tj].v)){
				if (exed>0) ans+=min(exed,e[tj].ct);
				else if (exed<0) ans+=min(e[ti].ct,-exed);
				else ans+=min(e[ti].ct,e[tj].ct);
			}
			
			if (exed==0){
				if (e[ti].ct>e[tj].ct) j--;
				else if (e[ti].ct==e[tj].ct) i++,j--;
				else i++;
			}
			else{
				if (exed>0){
					if (exed>e[tj].ct) j--;
					else if (exed==e[tj].ct) i++,j--;
					else i++;
				}
				else if (exed<0){
					if (-exed>e[ti].ct) i++;
					else if (-exed==e[ti].ct) i++,j--;
					else j--;
				}
			}
				
			if (exed==0){
				exed+=e[ti].ct-e[tj].ct;
			}
			else if (exed>0){
				exed-=e[tj].ct;
			}
			else exed+=e[ti].ct;
			
		}
	}
	cout<<ans;
	return 0;
}
