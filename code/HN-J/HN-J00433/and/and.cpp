#include <bits/stdc++.h>
using namespace std;
int n,m;
int er[35];
bool anser[35];
vector<int>v[35];
bool check(int x){
	for(int i=30;i>=0;i--){
		if(!anser[i])continue;
		for(int j=0;j<=v[i].size();i++){
			int u=v[i][j];
			if(x==v[i][j])return 1;
		}
	}
	return 0;
}
void solve(int x){
	//for(int i=0;i<=30;i++)cout<<er[i]<<" ";
	//cout<<"\n";
	//memset(er,0,sizeof(er));
	for(int i=0;i<v[x].size();i++){
		int u=v[x][i];
		//cout<<"check:"<<check(x)<<"\n";
		if(check(u))continue;
		int cnt=0;
		while(u){
			if(u%2)er[cnt]++;
			u/=2;
			cnt++;
		}
	}
	for(int i=x-1;i>=0;i--){
		if(er[i]>=m){
			anser[i]=1;
			if(i!=0)solve(i);
		}
	}
} 
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and1.in","r",stdin);
	//freopen("and.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	cin>>n>>m;
	//cout<<"n:"<<n<<" m:"<<m<<"\n";
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int t=x;
		//cout<<"t:"<<t<<"\n";
		int cnt=0;
		while(t){
			if(t%2){
				er[cnt]++;
				v[cnt].push_back(x);
				//cout<<"jin\n";
			}
			t/=2;    
			cnt++;
		}
	}
	//for(int i=0;i<=30;i++)cout<<er[i]<<" ";
	/**/
	for(int i=30;i>=0;i--){
		if(er[i]>=m){
			anser[i]=1;
			if(i!=0)solve(i);
			break;
		}
	}
	int sum=0;
	for(int i=0;i<=30;i++){
		if(anser[i])sum+=pow(2,i);
	}
	cout<<sum;
	
	return 0;
}
