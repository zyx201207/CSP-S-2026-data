#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	long long n,m,num[200005],maxn=0,sum=1,max2n=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> num[i];
		if(num[i]>maxn){
			maxn=num[i];
			max2n=maxn;
		}
		else{
			max2n=max(max2n,num[i]);
		}
		sum=sum&num[i];
	}
	if(m==1)
		cout << maxn;
	else if(m==n)
		cout << sum;
	//else if(m==2){
		//cout << maxn & max2n;
	//}
	return 0;
}
