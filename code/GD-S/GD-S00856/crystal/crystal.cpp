#include<bits/stdc++.h>
using namespace std;
long long n,m,num[1000000],sum,total[1000000],maxt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);

	for(long long i=n-1;i>0;i--){ 
		//cout<<"µÚ"<<i<<endl; 
		if(i<maxt)break;
		long long chance=m,nowt=1,k=i,next1=num[k];
		long long temp;
		if(temp==num[k-1]){
			k--;
			nowt++;
			continue;
		}
		while(chance>=0){ 
		if(next1>=0&&num[k-1]<=0)temp=abs(num[k-1])+next1;
		else if(next1>=0&&num[k-1]>=0)temp=next1-num[k-1];
		else if(next1<=0&&num[k-1]<=0)temp=abs(next1-num[k-1]);
		if(temp<=chance){
		//	cout<<chance<<" "<<temp<<" "<<k<<endl;
			nowt++;
			chance-=temp;
			k--;
		}else break;
		if(k==0)break;		
		}
		if(nowt>maxt){
		//cout<<num[i]<<endl;
		maxt=nowt;		
		}
		//cout<<endl;	
}
	cout<<maxt;
	return 0;
	
} 
