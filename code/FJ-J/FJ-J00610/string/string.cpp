#include<bits/stdc++.h>
using namespace std;
long long n,ans,sum;
pair<long long,char> cs[200010],s[200010];
long long qqzh[200010],hqzh[200010];
bool cmp(pair<long long,long long> x,pair<long long,long long> y){
	return x.second > y.second;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i = 1;i <= n;i++){
		cin>>cs[i].first>>cs[i].second;
		sum += cs[i].first;
	}
	for(long long i = 1,j = 1;i <= n;i++,j++){
		if(qqzh[i - 1] < sum / 2 && qqzh[i - 1] + cs[j].first > sum / 2 + (sum % 2)){
			long long l = cs[j].first;
			char c = cs[j].second;
			n++;
			qqzh[i] = sum / 2;
			s[i].first = sum / 2 - qqzh[i - 1];
			s[i].second = c;
			i++;
			qqzh[i] = l + qqzh[i - 2];
			s[i].first = qqzh[i] - qqzh[i - 1];
			s[i].second = c;
		}else{
			s[i] = cs[j];
			qqzh[i] = qqzh[i - 1] + s[i].first;
		}
	}
	
	for(long long i = n;i >= 1;i--){
		hqzh[i] = hqzh[i + 1] + s[i].first;
	}
//	for(long long i = 1;i <= n;i++){
//		cout<<s[i].first<<s[i].second<<endl;
//	}
	for(long long i = 1,he = n + 1,lea = 0;;i++){
		if(qqzh[i] > sum / 2){
			break;
		}
		long long l = 1,r = n,mid = (l + r) / 2;
		while(l < r){
//			cout<<mid<<' '<<hqzh[he] - lea<<endl;
			if(mid == l){
				if(hqzh[r] - hqzh[he] + lea < s[i].first){
					break;
				}else{
					l = r;
					break;
				}
			}
			if(hqzh[mid] > sum / 2){
				l = mid + 1;
			}else if(hqzh[mid] - hqzh[he] + lea < s[i].first){
				r = mid - 1;
			}else{
				l = mid;
			}
			mid = (l + r) / 2;
		}
		long long choose = l;
//		cout<<choose<<endl;
		pair<long long,long long> cha[40];
		for(long long j = 1;j <= 26;j++){
			cha[j] = {j,0};
		}
		cha[s[he].second - 96].second += lea;
		for(long long j = he - 1;j > choose;j--){
			cha[s[j].second - 96].second += s[j].first;
		}
		cha[s[choose].second - 96].second += s[choose].first - hqzh[choose] + qqzh[i];
		sort(cha + 1,cha + 27,cmp);
		for(long long j = 1;j <= 26;j++){
			if(cha[j].first == s[i].second - 96){
				ans += s[i].first - cha[j].second;
				break;
			}
		}
		lea = hqzh[choose] - hqzh[he] + lea - s[i].first;
		he = choose;
//		cout<<"lea"<<hqzh[choose]<<' '<<hqzh[he]<<' '<<lea<<' '<<s[i].first<<endl;
	}
	cout<<ans;
	return 0;
}
/*
6
100 a
100 a
100 a
100 b
100 b
100 b
*/
