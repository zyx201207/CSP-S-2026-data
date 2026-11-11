#include<bits/stdc++.h>
using namespace std;
int bin(int x){
	int c=0;
	int y=1;
	while(x){
		c+=x%2*y;
		x/=2;
		y*=10;
	}
	return c;
}
bool cmp(int x , int y){
	return x>y;
}
int v[1000000];
bool b[1000000];
int main(){
	freopen("D:/GD-J03043/and/and.in" , "r" , stdin);
	freopen("D:/GD-J03043/and/and.out" , "w" , stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	//sort(v+1 , v+1+n , cmp);
	
	long long max=0;
	long long max1=0 , max2=0;
	int first=0;
	for(int i=1;i<=n;i++){
			for(int j=1+i;j<=n;j++){
				
				if(v[i]&v[j]>=max and b[i]==0 and b[j]==0 and i!=j){
					int y=v[i] & v[j];
					
					max=y;
					max1=i;
					max2=j;
				}
				
			}
	}
	b[max1]=1;
	b[max2]=1;
	int max4=0;
	int max5=0;
	
	int max3=0;
	for(int k=2;k<m;k++){
	
		for(int i=1;i<=n;i++){
			first=0;
			max4=0;
			if(max&v[i]>=max && b[i]==0){
					
					max=v[i]&max;
					max3=i;
					first=1;
			}
		}
		b[max3]=1;
		
	}
	cout<<max;
}
