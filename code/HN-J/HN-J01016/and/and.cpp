#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;
int n,m,ans=0;int maxn=0;
int a[MAXN];
string s="";
vector<string> p(0);

bool cmp(int a,int b){
	return a>b;
}

string f(int x){
	string ans="";
	while(x>0){
		if(x%2==0){
			ans+='0';
		}
		else{
			ans+='1';
		}
		x/=2;
	}
//	ans+='1';
	maxn=max(maxn,int(ans.size())); 
	while(ans.size()<maxn){
		ans+='0';
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		p.push_back(f(a[i]));	
	}
	
	vector<int> q;
	for(int i=0;i<maxn;i++){
		int x=0;
		vector<int> pp;
		for(int j=0;j<n;j++){
			bool d=false;
			if(0==q.size()){
				d=true;
			}
			for(int v=0;v<q.size();v++){
				if(q[v]==j){
					d=true;
				}
			}
			if(p[j][i]=='1'&&d){
				x++;
				pp.push_back(j);
			}
//			cout<<p[i][j];
		}
//		cout<<endl;
		if(x>=m){
			s+='1';
			for(int i=0;i<pp.size();i++){
				q.push_back(pp[i]);
			}
		}
		else{
			s+='0';
		}
		
	}
	long long k=1;
	for(int i=maxn-1;i>=0;i--){
		ans=ans+k*int(s[i]-48);
		k*=2;
	}
	cout<<ans;
	return 0;
	
} 
