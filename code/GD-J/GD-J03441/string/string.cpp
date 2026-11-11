#include <bits/stdc++.h> 
using namespace std;
struct node{
	int num,pre;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		cin>>a[i].c;
		a[i].pre=sum+1;
		sum+=a[i].num;
	}
	for(int i=1;i<=sum/2;i++){
		int r=sum-i;char s;
		for(int j=n;j>=1;j--){
			if(a[n].pre>=r){
				n--;
			}
			if(a[n].pre<=r && r<=a[n].pre+a[n].num){
				s=a[n].c;
				break;
			}
		}
		if(s!=a[i].c)ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
