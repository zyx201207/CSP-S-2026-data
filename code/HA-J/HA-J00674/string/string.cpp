#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2e5+10;
struct node{
	long long sum;
	char ch;
};
node a[MAX_N];
int n;
long long total=0;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt++;
		cin>>a[cnt].sum>>a[cnt].ch;
		total+=a[cnt].sum;
		if(a[cnt].ch==a[cnt-1].ch){
			a[cnt-1].sum+=a[cnt].sum;
			cnt--;
		}
	}
	if(cnt==1){
		cout<<0<<'\n';
		return 0;
	}
	vector<char>vec(total+1, 'a');
	int l=1, r=0;
	for(int i=1;i<=cnt;i++){
		r+=a[i].sum;
		for(int j=l;j<=r;j++)vec[j]=a[i].ch;
		l=r+1;
	}
	long long res=0;
	for(long long j=1;j<=total/2;j++){
		if(vec[j]!=vec[total+1-j])res++;
	}
	cout<<res<<'\n';
	return 0;
}
