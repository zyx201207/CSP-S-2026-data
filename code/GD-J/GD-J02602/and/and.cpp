#include <bits/stdc++.h>
using namespace std;

int cnt(int a){
	int sum=0;
	while(a>0){
		if(a%2==1){
			sum++;
		}
		a>>=1;
	}
	return sum;
}

bool cmp(int &a,int &b){
	if(cnt(a)==cnt(b)){
		return a>b;
	}
	return cnt(a)>cnt(b);
}

int n,m,a[200005];
int main(){
	freopen("and4.in","r",stdin);
	freopen("and4.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int ans=a[0];
	for(int i=1; i<m; i++){
		ans&=a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
