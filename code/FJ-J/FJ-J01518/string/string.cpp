#include<bits/stdc++.h>
using namespace std;
long long qian[500001],hou[500001];
	char a[500001],b[500001];
	char zan[500001];
	long long zan1[500001];
	long long sum=0;
	long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>zan1[i];
		cin>>zan[i];
		sum+=zan1[i];
	}
	long long bans=sum/2;
	int ji=0;
	if(sum%2==1){
		bans++;
		ji++;
	}
	sum=0;
	long long ii,sb;
	for(int i=1;i<=n;i++){
		
		qian[i]=zan1[i];
		a[i]=zan[i];
		sum+=qian[i];
		if(sum>=bans){
			if(ji==1){
				qian[i]--;
			}
			hou[n-i+1]=sum-bans;
			b[n-i+1]=a[i];
			qian[i]-=sum;
			qian[i]+=bans;
			 ii=i+1;
			 sb=n-i+1;
			break;
		}
	}
	for(int i=ii;i<=n;i++){
		sb--;
		hou[sb]=zan1[i];
		b[sb]=zan[i];
	}
	sum=0;
	int q=1,h=1;
	while(q!=ii){
		if(a[q]!=b[h]){
			if(qian[q]<hou[h]){
				hou[h]-=qian[q];
				sum+=qian[q];
				q++;
			}
			else if(qian[q]==hou[h]){
				sum+=qian[q];
				q++;
				h++;
			}
			else{
				qian[q]-=hou[h];
				sum+=hou[h];
				h++;
			}
		}
		else{
			if(qian[q]<hou[h]){
				hou[h]-=qian[q];
				q++;
			}
			else if(qian[q]==hou[h]){
				q++;
				h++;
			}
			else{
				qian[q]-=hou[h];
				h++;
			}
		}
	}
	cout<<sum;
	return 0;
}
//3 2 a 2 b 1 c
