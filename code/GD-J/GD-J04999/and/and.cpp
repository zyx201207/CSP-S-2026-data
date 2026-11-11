#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;

long long maxnn=2147483647;//30 ones
/*bool oneee(int num){
	if(num<=2){
		return true;
	}
	int k=0;
	while(num>0){
		num= num&(num-1);
		k++;
		
	}
	if(k==1){
		return false;
	}
	return true;
}
long long solve1(){
	long long sum=maxnn;
	int ccc=n-1;
	for(int i=m;i>0;i--){
		
		sum&=a[ccc];
		ccc--;
	}
	return sum;
}

long long solve2(){
	long long sum=maxnn;
	int ccc=n-1;
	for(int i=m;i>0;i--){
		if(!oneee(a[ccc])){
			ccc--;
			i++;
		}else{
		
			sum&=a[ccc];
		ccc--;
		}
	}
	return sum;
}*/


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin>>n>>m;
	
		vector<int> aa;
		for(int i=0;i<m;i++){
			int t;
			cin>>t;
			aa.push_back(t);
		}
		sort(aa.begin(),aa.end());
		for(int i=0;i<n-m;i++){
			int t;
			cin>>t;
			if(t>aa[0]){
				aa[0]=t;
				sort(aa.begin(),aa.end());
			}
		}
		int anss=maxnn;
		for(int i=m-1;i>=0;i--){
			anss&=aa[i];
		}
		cout<<anss;
		return 0;
		
	
	
	
	
	/*for(int i=0;i<n;i++){
		int t;
		cin>>t;
		a.push_back(t);
	
	}
	sort(a.begin(),a.end());
	long long ans1=solve1();
	long long ans2=solve2();
	cout<<max(ans1,ans2);*/
	return 0;
}











