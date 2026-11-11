#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=2e5+5;

int n,m;
bool flag=1;
int l,r;
int ans=0;
int a[N];
string s[N];


bool cmp1(int a,int b){
	return a>b;
}

int main(){
	freopen ("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	//freopen("and3.in","r",stdin);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i];
		while(t){
			s[i]+=char(t%2);	
			t>>1;
		}
		if(flag){
			t=a[i]+1; 
			while(t&&!(t&1))t>>1;
			if(t)flag=0;
		}
	}
	
	if(m==1){
		sort(a+1,a+n+1,cmp1);	
		cout<<a[1];
		return 0;
	}
	 
	 
	if(flag){
		sort(a+1,a+n+1,cmp1);	
		cout<<a[m];
		return 0;
	}
	
	
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				string t;
				for(int k=0;k<min(s[i].size(),s[j].size());k++){
					if(s[i][k]=='1'&&s[j][k]=='1')t+='1';
					else t+='0';
				}
				int an=0;
				int idx=t.size()-1;
				while(idx>=0&&t[idx]=='0')idx--;
				for(int i=0;i<=idx;i++)
					if(t[i]=='1')
						an+=pow(2,i);
				ans=max(an,ans);
				}
			}
		
		cout<<ans;
		return 0;	
	
	}
	
	return 0;
} 
