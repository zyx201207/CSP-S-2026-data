#include <bits/stdc++.h>
using namespace std;
long long m,n;  //n’≈≈∆ m÷÷≈∆ 
long long arr[500005],crr[500005],sum[500005],drr[500005];
stack <long long> brr;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			crr[arr[i]]++;
			if(crr[arr[i]]==2){
				while(brr.front()!=arr[i]) brr.pop();
				crr[arr[i]]--;
			}else{
				brr.push(arr[i]);
			}
		}
		while(!brr.empty()){
			drr[brr.front()]++;
			brr.pop();
		}
		crr={0};
	}
	for(int i=1;i<=m;i++){
		cout<<drr[i]<<" ";
	}
	return 0;
}
