#include<bits/stdc++.h>
using namespace std;
long long l[100000111];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b;
	bool B=1;
	cin>>a>>b;
	for(long long i=1;i<=a;i++){
		cin>>l[i];
	}sort(l+1,l+a);
	//******
	l[0]=l[1];
	for(int i=1;i<=a;i++){
		if(l[i]!=l[i-1])b=0;
	}if(b){
		cout<<a;
		return 0;
	} 
	//*******若所有都相等，则不用修改 
	long long c=0;
	if(a%2)c=a/2+1;
	else c=a/2;
	for(int i=c;i<=a;i++){
		if(l[i]-l[c]<l[c]-l[a-i+1]&&b>=l[c]-l[a-i+1]){
			l[a-i+1]+=l[c]-l[a-i+1];
		}else if(l[i]-l[c]>l[c]-l[a-i+1]&&b>=l[c]-l[a-i+1]){
			l[a-i+1]+=l[c]-l[a-i+1];
		}else if(l[i]-l[c]==l[c]-l[a-i+1]&&b>=(l[c]-l[a-i+1]+l[i]-l[c])){
			l[a-i+1]+=l[c]-l[a-i+1];
			l[i]-=l[c]-l[i];
		}
	}
	int tot=1;
	for(int i=1;i<=a;i++){
		if(l[i]==l[i-1])tot++;
	}cout<<tot;
	return 0 ;
} 
