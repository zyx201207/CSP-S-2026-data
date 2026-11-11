#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5;
int a[N+10];
int cnt[N+10];
int desk[N+10]; int len=0;
int pos[N+10];
bool f[N+10];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int rd=1;rd<=n;rd++){
//		if(rd!=2)continue;
		cout<<"#"<<rd<<"\n";
		memset(desk,0, sizeof(desk));
		memset(pos,0, sizeof(pos));
		memset(f,0, sizeof(f));
		len=0;
		for(int i=rd;i<=n;i++){
			if(pos[a[i]]){
				len=pos[a[i]]-1;
				pos[a[i]]= ++len;
				desk[len]=a[i];
			}else{
				++len;
				pos[a[i]]=len;
				desk[len]=a[i];
			}
			
			for(int i=1;i<=len;i++) cout<<desk[i]<<" ";
			cout<<"\n";
		}
		for(int i=1;i<=len;i++)f[desk[i]]=1;
		for(int i=1;i<=m;i++)cnt[i]+=f[i];
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	
	
	
	return 0;
}
