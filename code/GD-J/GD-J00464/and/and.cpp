#include <bits/stdc++.h>
using namespace std;
struct er{
	long long num;
	long long one;
}; 
bool cnt(er a,er b){
	if(a.one!=b.one){
		return a.one>b.one;
	}else{
		return a.num>b.num;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	vector<er> nums(n+1);
	for(int i=0;i<n;i++){
		long long t,cnt=0;
		cin >> t;
		nums[i].num=t;
		while(t>0){
			if(t%2==1){
				cnt++;
			}
			t/=2;
		}
		nums[i].one=cnt;
	}
	sort(nums.begin(),nums.end(),cnt);
	long long g=nums[0].num;
	for(int i=1;i<m;i++){
		g=(g&nums[i].num);
	}
	cout << g;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
