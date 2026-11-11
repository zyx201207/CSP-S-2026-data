#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+10;
pair<int, char> a[MAXN];
bool cmp(const int& id, const int& iw, const int& jd, const int& jw){
	if(id<jd)return true;
	else if(id==jd)return iw<jw;
	else return false;
}
char get(const int &d){
	return a[d].second;
}
int getsize(const int& d){
	return a[d].first;
}
int getsize2(const int& d, const int& w, int flg){
	if(flg==1) return a[d].first-w+1;
	else return w;
}
int cnt=0;
void jmp(int& id, int& iw, int& jd, int& jw){
	if(get(id)!=get(jd))cnt++;
	iw++;
	if(iw>getsize(id)){id++; iw=1;}
	jw--;
	if(jw<1){jd--; jw=getsize(jd);}
}
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin>>n;
	int sum=0;
	for(int i=0; i<n; i++){
		cin>>a[i].first>>a[i].second;
		sum+=a[i].first;
	}
	for(int i=0; i<n; i++){
		if(sum>a[i].first)sum-=a[i].first;
		else break;
	}
	int id, iw, jd, jw;
	id=0; iw=1; jd=n-1; jw=a[n-1].first;
	while(cmp(id, iw, jd, jw)){	
		jmp(id, iw, jd, jw);
	}	
	cout<<cnt;
	return 0;
}
