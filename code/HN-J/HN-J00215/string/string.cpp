#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;//                      n=3
	long long a[n+1],num=0,mid=0;
	string b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];//         a[1]=2 a[2]=2 a[3]=1 b[1]=a b[2]=b b[3]=c
		num=num+a[i];//            num=2+2+1=5
	}
	if(n==1){//
		cout<<"0";
		return 0;
	}//
	if(n==2){
		if((a[1]+a[2])%2==0){
			cout<<a[n];
		}else{
			cout<<min(a[1],a[2]);
		}
	}
	if(num%2==1){
		mid=num/2+1;//              mid=3
	}else{
		mid=num/2;
	}
	int x=1;//                      x=1
	long long i=0,j=num;
	for(i=i+a[x];i<=mid;){//i=a[x]=a[1]=2	  i=a[x]=a[1]=2
		j=j-a[n];//         j=a[n]=a[3]1      j=a[n]=a[2]=2
		int ans;
		if(x==n){//                      /            
			num=num-a[n];//              /
		}
		if(i==j){//                      /             i=j=2
			if(b[n]==b[x]){ //           /             
				x++;            //       /
				n--;//                   /
				num=num-i*2; //          /
			}
		}else{
			ans=min(i,j);//         ans=j=1
			if(b[n]==b[x]){//       a!=c
				num=num-ans;//          /
			}
			if(ans==i){ 
				x++;
				a[n]=a[n]-ans;
			}else{
				n--;
				a[x]=a[x]-ans;
			}
		}        
		
	}
	cout<<num;
	return 0;
}
