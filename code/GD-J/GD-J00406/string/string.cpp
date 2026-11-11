#include<bits/stdc++.h>
using namespace std;
long long ans,n,a[200005],x[200005],x1[200005],y[200005],y1[200005];
char c[200005]; 
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long summ1=0,cnt1=1;
	while(summ1<sum/2){
		if(summ1+a[cnt1]<=sum/2){
			x[cnt1]=a[cnt1];
			x1[cnt1]=c[cnt1];
			summ1+=a[cnt1];
			cnt1++; 
		}else{
			x[cnt1]=sum/2-summ1;
			x1[cnt1]=c[cnt1];
			break;
		}
	}
	long long summ2=sum,cnt2=1,num=n;
	while(summ2>(sum+1)/2){
		if(summ2-a[num]>(sum+1)/2){
			y[cnt2]=a[num];
			y1[cnt2]=c[num];
			summ2-=a[num];
			cnt2++;
			num--;
		}else{
			y[cnt2]=summ2-(sum+1)/2;
			y1[cnt2]=c[num];
			break;
		}
	}
	summ2=sum-(sum+1)/2;
	long long op1=1,op2=1;
	while(1){
		if(op1>cnt1||op2>cnt2){
			break;
		}
		if(x[op1]==y[op2]){
			if(x1[op1]==y1[op2]){
				op1++;
				op2++;
			}else{
				ans+=x[op1];
				op1++;
				op2++;
			}
		}
		else if(x[op1]>y[op2]){
			if(x1[op1]==y1[op2]){
				x[op1]-=y[op2];
				op2++;
			}else{
				x[op1]-=y[op2];
				ans+=y[op2];
				op2++;
			}
		}
		else{
			if(x1[op1]==y1[op2]){
				y[op2]-=x[op1];
				op1++;
			}else{
				y[op2]-=x[op1];
				ans+=x[op1];
				op1++;
			}
		}
	}
	cout<<ans;
	return 0;
}
