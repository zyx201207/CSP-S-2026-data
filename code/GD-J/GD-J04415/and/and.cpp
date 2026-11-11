#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int inf=2147483647;
const int N=2e5+100;
int n,m;
int a[N];
string b[N];
int cnt;
int mxlen;
vector<int>q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push_back(i);
	}
	for(int i=1;i<=n;i++){
		int tmp=a[i];
		string s="";
		int len=0;
		while(tmp){
			if(tmp&1){
				s+='1';
			}
			else{
				s+='0';
			}
			len++;
			tmp>>=1;
		}
		mxlen=max(mxlen,len);
		b[++cnt]=s;
	}
	
	for(int i=1;i<=n;i++){
		int len=b[i].size();
		if(len<mxlen){
			for(int j=1;j<=mxlen-len;j++){
				b[i]+='0';
			}
		}
	}

	int I=mxlen-1;
	while(I>=0){
		vector<int>tmp;
	
		for(int i=0;i<q.size();i++){
			int idx=q[i];
			if(b[idx][I]=='1'){
				tmp.push_back(idx);
			}
		}
		int lentmp=tmp.size();

		if(lentmp!=m){
		
			if(lentmp>m){
				vector<int>newq;
				for(int i=0;i<lentmp;i++){
					newq.push_back(tmp[i]);
				}
				q=newq;
			}
		} 
		else{
		
			int ans=inf;
			for(int i=0;i<lentmp;i++){
				ans=(ans&a[tmp[i]]);
			}
			cout<<ans;
			return 0;
		}
		I--;
	} 
	int ans=inf;
	for(int i=0;i<m;i++){
		int idx=q[i];
		ans=(ans&a[idx]);
	}
	cout<<ans;
	return 0;
}

