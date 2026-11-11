#include<bits/stdc++.h>
using namespace std;
struct aa{
	int a;
	char c;
}as[200005];
int n;
map<char,char> bb;
long long ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool flag=1;
	
	for(int i=1; i<=n; i++){
		cin>>as[i].a>>as[i].c;
	}
	for(int i=1; i<=n/2; i++){
		if(as[i].a!=as[n-i+1].a||as[i].c==as[n-i+1].c){
			flag=0;
			break;
		}
	}
	int sum=0;
	if(flag==1){
		for(int i=1; i<=n/2; i++){
			sum+=as[i].a;
		}
		cout<<sum<<"\n";
		return 0;
	}
	int s=1;
	for(int i=1; i<=n; i++){
		char d=as[i].c;
		for(int j=1; j<=as[i].a; j++){
			bb[s]=d;
			s++;
		}
	}
	s--;
	int l=1,r=s;
	for(int i=1; i<=s/2; i++){
		if((int)bb[l]!=(int)bb[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans<<"\n" ;
	return 0;
}
