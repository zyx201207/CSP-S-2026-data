#include<bits/stdc++.h>
using namespace std;
struct node {
	long long a;
	char c;
}b[100050];
 long long n,sum=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
		sum+=b[i].a;
		b[i].a=sum;
	}
	b[0].a=0,b[0].c=b[1].c,b[n+1].a=sum,b[n+1].c=b[n].c;	
	int y,i=1,j=n;
	if(b[1].a<sum-b[n-1].a){
		y=b[1].a;
		j++;
	}
	else{
		if(b[1].a>sum-b[n-1].a){
		y=sum-b[n-1].a;
		i--;
		}
		else{
			y=b[1].a;	
		}
	}
	int x=0;
	while(y<=sum/2){
		if(b[i].c!=b[j].c){
			ans+=y-x;
		}
		x=y;
		if(b[i+1].a<sum-b[j-2].a){
			y=b[i+1].a;
			i++;
		}
		else{
			if(b[i+1].a>sum-b[j-2].a){
				y=sum-b[j-2].a+1;
				j--;
			}
			else{
				y=b[i+1].a;
				i++,j--;	
		}
	}
	}
	cout<<ans;
}
