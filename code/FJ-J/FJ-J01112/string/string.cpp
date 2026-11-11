#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<pair<int,char>> strseg;
	int n;
	unsigned long long cnt=0,ans=0;
	cin>>n;
	strseg.resize(n);
	for(int i=0; i<n; i++) {
		cin>>strseg[i].first>>strseg[i].second;
		cnt+=strseg[i].first;
	}
	unsigned long long i=0,j=cnt,indexi=0,indexj=n-1;
	while(i<j && indexi!=indexj) {
		vector<pair<int,char>> tmp;
		int tmpcnt=0;
		if(strseg[indexj].first>strseg[indexi].first) {
			tmp.push_back(make_pair(strseg[indexi].first,strseg[indexj].second));
			strseg[indexj].first=strseg[indexj].first-strseg[indexi].first;
			for(pair<int,char> x:tmp) if(x.second!=strseg[indexi].second) ans+=x.first;
			i+=strseg[indexi].first,j-=strseg[indexi].first,indexi++;
			continue;
		}
		while(indexi<n&& indexj>=0 && strseg[indexi].first>tmpcnt) {
			tmpcnt+=strseg[indexj].first;
			if(tmpcnt>strseg[indexi].first) {
				tmp.push_back(make_pair(strseg[indexj].first-(tmpcnt-strseg[indexi].first),strseg[indexj].second));
				strseg[indexj].first=tmpcnt-strseg[indexi].first;
				break;
			}
			tmp.push_back(strseg[indexj]);
			indexj--;
		}
		for(pair<int,char> x:tmp) {
			if(x.second!=strseg[indexi].second) ans+=x.first;
		}
		i+=strseg[indexi].first,j-=strseg[indexi].first,indexi++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
