#include <bits/stdc++.h>
using namespace std;
struct group{
    long long ai;
    char ci;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
    long long n,sum=0;
    cin>>n;
    group aaa[n];
    char bbb[1000000]={};
    for(int i=0;i<n;i++){
        cin>>aaa[i].ai;
		cin>>aaa[i].ci;
        sum+=aaa[i].ai;
        
    }
    
	long long p=0;
	for(int i=0;i<n;i++){
		for(int j=p;j<p+aaa[i].ai;j++){
			bbb[j]=aaa[i].ci;
		}
		p+=aaa[i].ai;
	}

	long long ans=0;
	long long first=0,second=sum-1;
	while(second-first>0){
		if(bbb[first]==bbb[second]){
			first++;
			second--;
			continue;
		}else{
			first++;
			second--;
			ans++;
			continue;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;


}

