#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
string s[200005];//32
string chg(int x){
	int cur=0;
	string ss;
	while(x){
		ss+=char(x%2+'0');
		x/=2;
	}
	while(ss.size()<32){
		ss+='0';
	}
	return ss;
}
bool is[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	int st=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		is[i]=1;
		s[i]=chg(a[i]); 
		//cout<<s[i]<<endl;
	} 
	int ans=0;
	
	for(int i=31;i>=0;i--){
		int cnt=0;
		vector<int>del;
		for(int j=1;j<=n;j++){
			//if(i==0) cout<<s[j][i]<<endl;
			if(!is[j]) continue;
			
			if(s[j][i]=='1'){
				cnt++;
				
			}else{
				del.push_back(j);
			}
		}
		if(cnt>=m) {
			//cout<<i<<endl;
			ans+=pow(2,i);
			for(int j:del)
				is[j]=0;
		}
	}
	cout<<ans;
	return 0;
}
