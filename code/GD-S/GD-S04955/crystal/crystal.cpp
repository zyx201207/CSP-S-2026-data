#include<bits/stdc++.h>
using namespace std; 
constexpr int maxn = 500000;
long long nums[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> nums[i];
	}
	sort(nums,nums+n);

//	for (int i = 0 ; i<n; i++){
//		cout << nums[i] << endl;
//	} 


	long long last,next,len,step,tmp;
	long long end = 0; 
	last = 0;
	len = 1;
	for(int i = 1 ,j = 0;i<n;i++){
		step =abs(nums[i]-nums[i-1]);
		next += last + len*step;
//		cout << nums[i]<<" "<<step << " " << len << " " << next << endl;
//			cout << i << " " << j << endl;
		while (next > m){
			step = abs(nums[i]-nums[j]);
			next -= step;
			j++;
		}
		len = i-j+1;
//			cout << i << " " << j << endl;	
		end = end > len ? end : len;
//		cout << i << " "<< next << " " << j << endl;
//		cout << nums[i]<<" "<<step << " " << len << " " << next << endl;
	}
	cout << end;
//	cout << 1;
//	cout << endl << nums[0] << endl << nums[n-1] << endl;
	
	return 0;
}
