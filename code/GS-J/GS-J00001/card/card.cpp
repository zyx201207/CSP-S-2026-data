#include<bits/stdc++.h>
using namespace std;
#define itn int
#define inl inline
#define re register
#define pos ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
const int N=5e5+10;
//开long long了否
//数组大小足够否
//freopen去掉注释了否
int n,m;
char a[N];
string s;
int cnt[N];
signed main(){
	//freopen("r","card.in",stdin);
	//freopen("w","card.out",stdout);
	pos;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(s.find(a[j])!=string::npos){
				s+=a[j];
			}else{
				s.erase(i,j);
				s+=a[j];
			}
		}
		for(int j=0;j<n;j++){
			if(s.find(a[j])!=string::npos){
				cnt[a[j]-'0']++;
			}
		}
	}
	for(int i=0;i<m;i++) cout<<cnt[i]<<' ';
	return 0;
}
