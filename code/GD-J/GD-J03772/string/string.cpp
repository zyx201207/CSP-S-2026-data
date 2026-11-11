#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("string.in");
	ofstream fout("string.out");
	int n;
	fin>>n;
	long long sum=0;
	int a[n];
	char c[n];
	for(int i=0;i<n;++i){
		fin>>a[i]>>c[i];
		sum+=a[i];
	}
	bool b=sum&1;
	sum=sum/2;
	long long cnt=0;
	int lpos=0,now=a[0];
	while(sum){
		if(now>sum){
			now-=sum;
			sum=0;
		}
		else{
			sum-=now;
			++lpos;
			now=a[lpos];
		}
	}
	int last=now,rpos=lpos;
	now=a[lpos]-now;
	if(b)
		--last;
	if(last<=0)
		last=a[++rpos]+last;
	while(rpos<n&&lpos>=0){
		if(now<=last){
			if(c[lpos]==c[rpos]){
				last-=now;
				now=0;
			}
			else{
				cnt+=now;
				last-=now;
				now=0;
			}
		}else{
			if(c[lpos]==c[rpos]){
				now-=last;
				last=0;
			}
			else{
				cnt+=last;
				now-=last;
				last=0;
			}
		}
		if(now==0)
			now=a[--lpos];
		if(last==0)
			last=a[++rpos];
	}
	fout<<cnt;
	return 0;
}
