#include <bits/stdc++.h>
using namespace std;
#define int long long
struct strset{
	unsigned long long num;
	char ch0;
}arr[200005] = {0};
long long _top = 0;
inline unsigned long long getlbot(unsigned long long index,unsigned long long num){
	if(index == 1)return num;
	else return num - arr[index - 2].num;
}
inline unsigned long long getrbot(unsigned long long index,unsigned long long num){
	return arr[index - 1].num - num + 1;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin >> n;
	int t0;char t1;
	unsigned long long sum = 0;
	for(int i = 0;i < n;i++){
		cin >> t0 >> t1;sum += t0;
		if(_top != 0 && t1 == arr[_top - 1].ch0){
			arr[_top - 1].num += t0;
		}else{
			arr[_top].num = t0;
			arr[_top++].ch0 = t1;
		}
	}for(int i = 0;i < _top;i++){
		if(i != 0)arr[i].num = arr[i].num + arr[i - 1].num;
	}
	
	bool tomod = sum % 2;int mid = 0;
	unsigned long long diff = 0;
	unsigned long long left,right;
	if(tomod) mid = (sum + 1) / 2,left = mid - 1,right = mid + 1;
	else mid = sum / 2,left = mid,right = mid + 1;
	if(_top == 1){cout << 0;return 0;}
	unsigned long long bott = 1;int li,ri;
	
	for(int i = 0;i < _top;i++){
		if(bott <= left && left <= arr[i].num)li = i + 1;
		if(bott <= right && right <= arr[i].num){ri = i + 1;break;}
		bott = arr[i].num + 1;
	}int lost = 0,rost = 0;
	
	while(left != 0 && right != (sum + 1)){
        lost = getlbot(li,left),rost = getrbot(ri,right);
		if(lost < rost){
			int nzero = lost;
			if(arr[li - 1].ch0 != arr[ri - 1].ch0)diff += nzero;
			left -= nzero;lost -= nzero;
            if(lost == 0) li--;
			right += nzero;rost -= nzero;
            if(rost == 0) ri++;
		}else if(lost > rost){
			int nzero = rost;
			if(arr[li - 1].ch0 != arr[ri - 1].ch0)diff += nzero;
			left -= nzero;lost -= nzero;
            if(lost == 0) li--;
			right += nzero;rost -= nzero;
            if(rost == 0) ri++;
		}else{
			int nzero = lost;
			if(arr[li - 1].ch0 != arr[ri - 1].ch0)diff += nzero;
			left -= nzero;lost -= nzero;
            if(lost == 0) li--;
			right += nzero;rost -= nzero;
            if(rost == 0) ri++;
		}
	}
	cout << diff;
	return 0;
}
