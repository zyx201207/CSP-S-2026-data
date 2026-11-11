#include<bits/stdc++.h>
using namespace std;
long long int n,sum;
long long int num,x,y;//num为待检查数量 ,x为前项指针，y为后项指针 
int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		num+=a[i];
	}
	num/=2;
	x=1,y=n;
	while(num!=0){
		if(a[x]<num){
			if(a[y]<a[x]){
				if(b[x]!=b[y]){
					sum+=a[y];
				}
				num-=a[y];
				a[x]-=a[y];
				a[y]=0;
				y--;
			}else if(a[y]==a[x]){
				if(b[x]!=b[y]){
					sum+=a[y];
				}
				num-=a[y];
				a[x]=0,a[y]=0;
				y--;
				x++;
			}else if(a[y]>a[x]){
				if(b[x]!=b[y]){
					sum+=a[x];
				}
				num-=a[x];
				a[y]-=a[x];
				a[x]=0;
				x++;
			}
		}else if(a[x]==num){
			if(a[y]<a[x]){
				if(b[x]!=b[y]){
					sum+=a[y];
				}
				num-=a[y];
				a[x]-=a[y];
				a[y]=0;
				y--;
			}else if(a[y]==a[x]){
				if(b[x]!=b[y]){
					sum+=a[y];
				}
				break;
			}else if(a[y]>a[x]){
				if(b[x]!=b[y]){
					sum+=a[x];
				}
				num-=a[x];
				a[y]-=a[x];
				a[x]=0;
				x++;
			}
		}else{
			for(int i=y;i>x;i--){
				if(b[i]!=b[x]){
					sum+=a[i];
				}
			}
			break;
		}
	}
	cout<<sum<<endl;

	return 0;
}


