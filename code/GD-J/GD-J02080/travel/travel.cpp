#include<bits/stdc++.h>
using namespace std;
char mapp[7]={0,0,0,1,-1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int a_jie=(a[0]-'0')*10+a[1]-'0';
	int c_jie=(c[0]-'0')*10+c[1]-'0';
	if(a_jie==c_jie){
		cout<<1;
		int b_pai=(b[0]-'0')*10+b[1]-'0';
		int d_pai=(d[0]-'0')*10+d[1]-'0';
		if(b_pai==d_pai){
			cout<<1;
			int b_ce=mapp[b[2]-'A'];
			int d_ce=mapp[d[2]-'A'];
			if(b_ce==d_ce){
				cout<<1;
				int b_hao=b[2],d_hao=d[2];
				if(b_hao<='C'){
					if(d_hao>='D'){
						cout<<0;
					}else if(abs(d_hao-b_hao)==1){
						cout<<1;
					}else{
						cout<<0;
					}
				}else{
					if(b_hao=='D'){
						if(d_hao=='F'){
							cout<<1;
						}else{
							cout<<0;
						}
					}else{
						if(d_hao=='D'){
							cout<<1;
						}else{
							cout<<0;
						}
					}
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}//100+100+75+52=327
//wo yao shang mi huo xin wei da shang
//rp++ QwQ
