#include<bits/stdc++.h>
using namespace std;
struct deng{
	long long shu;
	char zi;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cha=0;
	long long head=1,tail=1;
	cin>>n;
	deng a[n+10]={0},b[n+10]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i].shu>>a[i].zi;
		b[n-i+1].shu=a[i].shu;
		b[n-i+1].zi=a[i].zi;
	}
	while(head<=n && tail <=n){
		if(a[head].zi==b[tail].zi){
			if(a[head].shu>b[tail].shu){
				tail++;
				a[head].shu-=b[tail].shu;
			}
			else if(a[head].shu==b[tail].shu){
				head++;
				tail++;
			}
			else if(a[head].shu<b[tail].shu){
				head++;
				b[tail].shu-=a[head].shu;
			}
		}else{
			if(a[head].shu>b[tail].shu){
				tail++;
				a[head].shu-=b[tail].shu;
				cha+=b[tail].shu;
			}
			else if(a[head].shu==b[tail].shu){
				cha+=a[head].shu;
				head++;
				tail++;
				
			}
			else if(a[head].shu<b[tail].shu){
				head++;
				b[tail].shu-=a[head].shu;
				cha+=a[head].shu;
			}
		}
	}
	
	cout<<cha/2;
	return 0;
} 
