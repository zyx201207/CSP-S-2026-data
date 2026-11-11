#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,pos;
string a[N];
long long k,ans;
bool cmp(string l,string r){
	return l>r;
}
void turn(long long x,int pos){
	int cnt;
	for(cnt=0;x!=0;cnt++){
		a[pos]+=char(x%2+'0');
		x/=2;
	}
	for(cnt=a[pos].size();cnt<30;cnt++){
		a[pos]+='0';
	}
	reverse(a[pos].begin(),a[pos].end());
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	pos=n;
	for(int i=1;i<=n;i++){
		cin>>k;
		turn(k,i);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=pos;i++)cout<<a[i]<<endl;
	for(int i=0;i<=29;i++){
		int sum=0;
		int y=0;
		for(int j=1;j<=pos;j++){
			if(a[j][i]=='1')sum++;
			if(sum>=m){
				y=1;
				ans+=pow(2,29-i);
				break;
			}
		}
		if(y==1)
			for(int j=1;j<=pos;j++){
				if(a[j][i]=='0'){
					swap(a[j][i],a[pos][i]);
					pos--;
				}
			}
	}
	cout<<ans<<endl;
	
	return 0;
}
