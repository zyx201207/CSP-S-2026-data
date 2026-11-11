#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],mr=-999,cnt[35],ans,mk[N];
vector<int> w[35];
string b[N];
bool cmp(int x,int y){
	return x>y;
}
string bin(int d){
	string r="",str="";
	while(d>0){
		if(d%2==1){
			r+='1';
		}else r+='0';
		d/=2;
	}
	int pp=r.size();
	mr=max(pp,mr);
	return r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=bin(a[i]);
	}
	for(int i=1;i<=n;i++){
		string st="";
		for(int j=mr-1;j>=0;j--){
			if(j+1>b[i].size()) st+='0';
			else st+=b[i][j];
		}
		b[i]=st;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<mr;j++){
			if(b[i][j]=='1'){
				w[j].push_back(i);
				cnt[j]++;
			}
		}
	}
	string an="";
	int scf;
	bool fst=1;
	for(int i=0;i<mr;i++){
		int ls=cnt[i];
		if(cnt[i]>=m){
			an+='1';
			for(int j=i-1;j<mr;j++){
				for(int k=1;k<=cnt[j];k++){
					bool flag=0;
					for(int o=1;o<=cnt[i];o++){
						if(w[j][k]==w[i][o]){
							flag=1;
							break;
						}
					}
					if(!flag){
						w[j][k]=0;
						cnt[j]--;
					}
				}
			}
		}else an+='0';
	}
	int cm=1;
	for(int i=mr-1;i>=0;i--){
		ans+=(an[i]-'0')*cm;
		cm*=2;
	}
	cout<<ans;
    return 0; 
}
