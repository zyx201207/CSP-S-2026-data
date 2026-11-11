#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=200005; 
int n,m;
int value[N];
bool ok[N];
int a[N][35];
vector<int>v;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ok[i]=true;
		cin>>value[i];
		int temp=value[i];
		int id=0;
		while(temp!=0){
			a[i][id]+=(temp%2);
			id++;
			temp/=2;
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=34;j>=0;j--){
			cout<<a[i][j];
		}
		cout<<endl;
	}*/
	int num=0;
	int temp_ans;
	int ans2=(1>>31)-1;
	for(int i=34;i>=0;i--){
		v.clear();
		num=0;
		temp_ans=(1<<31)-1;
		for(int j=1;j<=n;j++){
			if(ok[j]==true&&a[j][i]==1){
				v.push_back(j);
				num++;
			}
		}
		if(num<m) continue;
		else if(num==m){
			int ans1=(1<<31)-1;
			for(int node:v){
				ans1=ans1&value[node];
			}
			cout<<ans1<<endl;
		}
		else if(num>m){
			for(int j=1;j<=n;j++){
				if(a[j][i]==0) ok[j]=false;
				if(ok[j]) ans2&=value[j];
			}
		}
	}
	cout<<ans2<<endl;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//and
