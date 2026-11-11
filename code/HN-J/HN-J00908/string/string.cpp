#include<bits/stdc++.h>
using namespace std;
struct put{
	long long num;
	char word;
}uses[200005];
long long n,sum;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>uses[i].num>>uses[i].word;
	long long l=1,r=n;
	while(l<r){
		long long ad1=uses[l].num,ad2=uses[r].num;
		if((ad1!=ad2)||(uses[l].word!=uses[r].word)){
			sum+=uses[l].word!=uses[r].word?min(ad1,ad2):0;
			uses[l].num=ad1>ad2?ad1-ad2:0;
			uses[r].num=ad2>ad1?ad2-ad1:0;
			l+=(uses[l].num==0);
			r-=(uses[r].num==0);
		}
		else
			l+=1,r-=1;
	}
	cout<<sum;
	return 0;
}



