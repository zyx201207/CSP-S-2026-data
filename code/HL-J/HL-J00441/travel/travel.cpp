#include<bits/stdc++.h>
using namespace std;
struct seat{
	int x;
	string id;
}a,b;
int paia,paib,cnt;
char s[6]={'A','B','C','D','F'};
bool f[6];
int main(){
	freopen("travel.in","r",stdin);	
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>a.x>>a.id>>b.x>>b.id;
	if(a.x!=b.x){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		paia=(a.id[0]-'0')*10+a.id[1]-'0';
		paib=(b.id[0]-'0')*10+b.id[1]-'0';
		if(paia!=paib){
			cout<<"000";
			return 0;
		}else{
			cout<<1;
			char uida=a.id[2],uidb=b.id[2];
			if(uida=='F'&&uidb=='D'||uida=='F'&&uidb=='D'){
				cout<<11;
				return 0;
			}else{
				for(int i=0;i<5;i++){
					if(uida==s[i]||uidb==s[i])
						f[i]=1;
				}
				for(int i=0;i<3;i++){
					cnt+=f[i];
				}
				if(cnt<2){
					cout<<"00";
					return 0;
				}else{
					cout<<1;
					int as=-1,bs=-1;
					for(int i=0;i<3;i++){
						if(f[i]&&as==-1)
						as=i;
						else if(f[i]&&as!=-1)
						bs=i;
					}
						if(bs-as==1){
						cout<<1;
						return 0;
					}else{
						cout<<0;
						return 0;
					}
				}
				
				}
				}
			}
		
	

	return 0;
}
