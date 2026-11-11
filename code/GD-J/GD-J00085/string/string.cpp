#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
long long number[N+5];
char c[N+5];
long long total=0,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>number[i]>>c[i];
		total+=number[i];
	}
	total=total*1.0/2+0.5;
	long long num_l=0,num_r=0,r=n;
	for(int i=1;i<=n;i++){
		if(num_l+number[i]<=total){
			num_l+=number[i];
			while(num_r+number[r]<=num_l){
				if(c[r]!=c[i]){
					cnt+=number[r];
				}
				num_r+=number[r];
				r--;
			}
			if(c[r]!=c[i]){
				cnt+=num_l-num_r;
			}
			number[r]-=num_l-num_r;
			num_r=num_l;
		}else{
			num_l=total;
			while(num_r+number[r]<=num_l){
				if(c[r]!=c[i]){
					cnt+=number[r];
				}
				num_r+=number[r];
				r--;
			}
			if(c[r]!=c[i]){
				cnt+=num_l-num_r;
			}
			number[r]-=(num_l-num_r);
			num_r=num_l;
			break;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
