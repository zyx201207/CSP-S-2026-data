#include<bits/stdc++.h>
using namespace std;

int n,m,j,Tmp;
unsigned long a,Ans;
int Cnt[35];
int Pos[200005][35];
vector<int> Cos;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		j=0;
		while(a>0){
			Cnt[++j]+=a%2;
			Pos[i][j]=a%2;
			a/=2;
		}
		//cout<<i<<' ';
		//for(int j=30;j>=1;j--) cout<<Pos[i][j];
		//cout<<endl;
	}
	for(int i=30;i>=1;i--){
		if(Cnt[i]>=m){
			for(int j=1;j<=n;j++){
				if(!Pos[j][i]){
					for(int p=i-1;p>=1;p--){
						Cnt[p]-=Pos[j][p];
					}
				}else{
					Cos.push_back(j);
				}
			}
			Ans+=pow(2,i-1);
			//cout<<Ans<<endl; 
			Tmp=i;
			break;
		}
	}
	for(int i=Tmp-1;i>=1;i--){
		if(Cnt[i]<m) continue;
		Ans+=pow(2,i-1);
		//cout<<Cnt[i]<<' '<<Ans<<' '<<i<<endl; 
		for(int j=0;j<Cos.size();j++){
			//cout<<Cos[j]<<' ';
			if(Cos[j]==0) continue;
			if(!Pos[Cos[j]][i]){
				for(int p=i-1;p>=1;p--){
					Cnt[p]-=Pos[Cos[j]][p];
				}
				Cos[j]=0;
			}
		}
		//cout<<endl;
	}
	cout<<Ans;
	return 0;
}
