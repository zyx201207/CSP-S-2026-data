#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[200020];

bool sort_a(int xx,int yy){
	return xx>yy;
}

struct node{
	int x;
	int v;
}num[200020];

bool check(int xx){
	int t=xx+1;
	while(t>2){
		t/=2;
		if(t%2==1){
			return false;
		}
	}
	return true;
}

long long ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1,sort_a);
	
	if(m==1){
		cout<<a[1]<<endl;
		return 0;
	}

	int t=a[1];
	int len=1;
	num[len].x=t;
	for(int i=1;i<=n;i++){
		if(a[i]==t){
			num[len].v++;
		}
		else{
			t=a[i];
			num[++len].x=t;
			num[len].v++;
		}
	}
	
	for(int i=1;i<=len;i++){
		if(num[i].v>=m){
			cout<<num[i].x<<endl;
			return 0;
		}
		else{
			if(check(num[i].x)){
				m-=num[i].v;
			}
		}
	}
	
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
