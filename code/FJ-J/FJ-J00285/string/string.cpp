#include<bits/stdc++.h>
using namespace std;
struct s{
	int num;
	char c;
}a[200005];
int n,cnt;
int sum;
string x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		sum+=a[i].num;
	}
	if(n==2){
		if(a[1].c==a[2].c){
			cout<<0;
		}else{
			cout<<abs(a[1].num-a[2].num);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].num;j++){
			x+=a[i].c;
		}
	}
	if(sum%2==0){
		for(int i=0;i*2<sum;i++){
			int j=sum-i-1;
			if(x[i]!=x[j]){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}if(sum%2==1){
		for(int i=0;i*2<sum;i++){
			int j=sum-i-1;
			if(x[i]!=x[j]){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	
	return 0;
}
