#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<long long> pf2;
inline int count(const vector<long long> &pf, int pos, int itms) {
	int sum=0;
	for(int i=0; i< itms; i++){
		sum += pf[pos-i] * (itms-i);
	}
	return sum;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<long long> raw(n);

	for(auto &i: raw) {
		cin >> i;
	}
	vector<long long> pf(n);

	sort(raw.begin(), raw.end());

	bool hasone = 0;
	for(int i=1;i<n;i++){
		hasone |= (pf[i] = raw[i] - raw[i-1]);
	}
	if(!hasone) {
		cout << n;
	}

	int max2=0;

	if(n > 100000){
		for(int i = n-1; i>=0; i=i*99/100-1){
			int minst=max2,maxst=i+1,itms=(minst+maxst)/2;
			while(minst+1<maxst){
				if(count(pf, i, itms) <= m){
					max2 = itms;
					minst = itms;
					itms = (minst+maxst)/2;
				}else{
					maxst = itms;
					itms = (minst+maxst)/2;
				}
			}
		}
	}else
		for(int i = n-1; i>=0; i--){
			int minst=max2,maxst=i+1,itms=(minst+maxst)/2;
			while(minst+1<maxst){
				if(count(pf, i, itms) <= m){
					max2 = itms;
					minst = itms;
					itms = (minst+maxst)/2;
				}else{
					maxst = itms;
					itms = (minst+maxst)/2;
				}
			}
		}
	cout << max2+1 << '\n';
}