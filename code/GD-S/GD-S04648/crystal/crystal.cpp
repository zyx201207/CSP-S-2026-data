#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("crystal.in.txt","r",stdin);
	freopen("crystal.out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[400005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int qzh[400005];
	qzh[0]=a[0];
	sort(a,a+n);
	for(int i=1;i<n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	int maxnum=0;
	for(int i=0;i<n;i++){					//500000
		int b=a[0],e=a[n-1];
		while(b<=e){						//20
			int mid=(b+e)/2;
			int dif=0;
			int num=0;
			for(int j=i;a[j]<=mid;j++){		
				dif+=mid-a[j];
				num++;
				if(dif>m){
					break;
				}
			}
			if(num>maxnum){
				maxnum=num;
			}
			if(dif>m){
				e=mid-1;
			}
			else if(dif<=m){
				b=mid+1;
			}
		}
	}
	cout<<maxnum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
