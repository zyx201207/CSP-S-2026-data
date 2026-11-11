#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	cin>>n;
	int cnt=0;
	char s[10005];
	long long sum=1;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=sum;j<=sum+a;j++){
			s[j]=c;
		}
		sum+=a;		
	}
	sum--;
	long long mid;
	if(sum%2==1){
		mid=sum/2;
		long long k=mid+2;
		for(long long i=mid;i>=1;i--){
			if(s[i]!=s[k++]){
				cnt++;
			}
		}
	}else{
		mid=sum/2;
		long long k=mid+1;
		for(long long i=mid;i>=1;i--){
			if(s[i]!=s[k++]){
				cnt++;
			}
		}
	}

//	cout<<mid<<endl;
	
	cout<<cnt;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
