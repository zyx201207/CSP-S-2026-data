#include<iostream>
#include<cstdio>
using namespace std;
long long a[100005],li,sum[100005],rli,cnt;
int n;
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		//cin;
		sum[i]=sum[i-1]+a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	li=sum[n]/2;
	for(int i=1;i<=n;i++){
		if(sum[i]>=li){
			rli=i;
			break;
		}
	}
	int i=1,j=n;
	while(i<j){
		if(c[i]==c[j]){
			//cout<<1;
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				a[i]=0;
				i++;
			}else{
				a[i]=a[j]=0;
				i++;
				j--;
			}
		}else{
			//cout<<2;
			if(a[i]>a[j]){
				cnt+=a[j];
				a[i]-=a[j];
				a[j]=0;
				j--;
				//cout<<1;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				cnt+=a[i];
				a[i]=0;
				i++;
				//cout<<2;
			}else{
				cnt+=a[i];
				a[i]=a[j]=0;
				i++;
				j--;
				//cout<<3;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
