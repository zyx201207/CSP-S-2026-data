#include<bits/stdc++.h>
using namespace std;
long long num[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int L;
	cin>>L;
	long long sum=0;
	for(int i=1;i<=L;i++){
		cin>>num[i]>>c[i];
		sum+=num[i];
	}
	int yu=sum%2;
	sum/=2;
	long long total=0;
	long long tmp=0;
	int i=0;
	long long left=1,right=L;
	while(tmp<sum){
		tmp+=min(num[left],num[right]);
		if(c[left]!=c[right]){
			total+=min(num[left],num[right]);
		}
		if(num[left]<num[right]){
			num[right]-=num[left];
			left++;
		} else if(num[right]==num[left]){
			right--;
			left++;
		} else {
			num[left]-=num[right];
			right--;
		}
	}
	cout<<total;
	return 0;
}
