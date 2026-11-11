#include<bits/stdc++.h>
using namespace std;
struct zifu{
	int num;
	char x;
};
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	zifu a[200001];
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].x;
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	else if(n==2){
		if(a[1].x!=a[2].x){
			cout<<min(a[1].num,a[2].num);
		}
		else{
			cout<<"0";
		}
		return 0;
	}
	int cnt=0;
	int k=0;
	if(n%2==0){
		k=n/2;
	}
	else{
		k=n/2+1;
	}
	for(int i=1;i<=k;i++){
		if(a[i].x!=a[n-i+1].x){
			cnt+=max(a[i].num,a[n-i+1].num);
		}
		else{
			if(a[i].num!=a[n-i+1].num){
				cnt+=min(a[i].num,a[n-i+1].num);
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
