#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
bool cnt[N][35];
int a[N];
int n,m;
int f[N];
//int a[N];
unordered_set<int> fv;
unordered_set<int> ev;
unordered_map<int,int> emp;
unordered_map<int,int> fmp;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int fcnt=-1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		string s="";
		while(x>0){
			s=s+to_string(x%2);
			x/=2;
		}
		//cout<<s<<endl;
		fcnt=max(fcnt,(int)s.size()-1);
		for(int j=0;j<(int)s.size();j++) cnt[i][j]=s[j]-'0';
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=fcnt;j++) cout<<cnt[i][j]<<" ";
//		cout<<endl;
//	}
	if(n==1){
		cout<<a[1]<<endl;
		return 0;
	}
	
	for(int i=fcnt;i>=0;i--){
		int ecnt=0;
		if(fv.empty()) fv=ev;
		if(emp.empty()) emp=fmp;
		for(int j=1;j<=n;j++){
			if(!fmp.count(j)){
				if(cnt[j][i]) ecnt++;
				else{
					fv.insert(j);
					emp[j]=1;
				}
			}
			
		}
		//cout<<"ecnt"<<ecnt<<endl;
		if(ecnt>=m){
			ev=fv;
			fmp=emp;
			if(ecnt==m) break;
		}else{
			fv.clear();
			emp.clear();
		}
		
	}
	int ans=0;
	for(auto i:ev){
		f[i]=1;
		//cout<<i<<" ";
	}
	//cout<<endl;
	int qcnt=0;
	for(int i=1;i<=n;i++){
		if(!fmp.count(i)){
			if(qcnt==0) ans=a[i],qcnt=1;
			else ans&=a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

