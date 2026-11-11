#include<bits/stdc++.h>
using namespace std;
long long pup=pow(10,12);
int main(){
	int n=0;
	long long m=0;
	freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long c[n+1]={0};
	long long value=0;
	long long c1[n+1];
	for(int i=0;i<n;i++){
		cin>>c[i];
		value+=c[i]/n;
	}
	for (int i=0;i<n;i++){
		if(i==0){
			c1[0]=c[i]-value;
		}else{
			bool flag=false;
			for(int j=0;j<i;j++){
				if(c1[j]>c[i]-value){
					flag=true;
					for(int f=i-1;f>=j;f--){
						c1[f+1]=c1[f];
					}
					c1[j]=c[i]-value;
					break;
				}
			}
			if(not flag){
				c1[i]=c[i]-value;
			}
		}
	}
	long long sums=0;
	bool flag=false;
	for(int i=0;i<n;i++){
		sums+=abs(c1[i]);
		if(sums>m){
			cout<<i<<'\n';
			flag=true;
			break;
		}
	}
	if(not flag){
		cout<<n<<'\n';
	}
	return 0;
} 
