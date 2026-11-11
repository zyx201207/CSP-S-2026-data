#include<bits/stdc++.h>
#define int long long
using namespace std;
struct zm{
	int many;
	char c;
	bool mj;
}; zm a[222222], t_a[222222];
signed main(){
	freopen("string.in","r", stdin);
	freopen("string.out","w", stdout);
	int cnt = 0;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].many >> a[i].c;
		//a[i].id = i;
		cnt += a[i].many;
	}
	int tmp = 0;
	int ji;
	if(cnt % 2 == 1)ji = 1;
	else ji = 0;
	cnt /= 2;
	int i = 1;
	int flag = 0;
	for(i = 1; tmp < cnt; i++)
	{
		tmp += a[i].many;
		if(tmp <= cnt)
		{
			t_a[i].mj = 1;
			t_a[i].many = a[i].many;
			t_a[i].c = a[i].c;
		}
		else{
			int tmp1 = cnt + a[i].many - tmp, tmp2 = tmp - cnt;
			if(ji)tmp2 -= 1;
			t_a[i].many = tmp1;
			t_a[i].mj = 1;
			t_a[i].c = a[i].c;
			i++;
			t_a[i].many = tmp2;
			t_a[i].c  = a[i - 1].c;
			flag = 1;
			break;
		}
	}
	if(flag){
	i++;
	for(i; i <= n + 1; i++){
		t_a[i].many = a[i - 1].many;
		t_a[i].c = a[i - 1].c;
		}
	}
	else{
		for(i; i <= n; i++){
			t_a[i].many = a[i].many;
			t_a[i].c = a[i].c;
		}
	}
	int l = 1, r = n;
	if(flag) r++;
	int ans = 0;
	while(l < r){
	//	cout << "&&" << l << "^^" << r << "??" << ans << endl;
	//	cout << t_a[l].c << "   " << t_a[r].c << endl; 
		if(t_a[l].many < t_a[r].many){
			t_a[r].many -= t_a[l].many;
			if(t_a[l].c != t_a[r].c) ans += t_a[l].many;
			l++;
		}
		else if(t_a[r].many < t_a[l].many){
			t_a[l].many -= t_a[r].many;
			if(t_a[l].c != t_a[r].c) ans += t_a[r].many;
			r--;
		}
		else{
			if(t_a[l].c != t_a[r].c)ans += t_a[r].many;
			l++;
			r--; 
		}
	}
//	 6
// 1000000000 a
// 1000000000 a
// 1000000000 a
// 1000000000 b
// 1000000000 b
// 1000000000 b
//Trick||Treat!
	cout << ans;
	return 0;
}
