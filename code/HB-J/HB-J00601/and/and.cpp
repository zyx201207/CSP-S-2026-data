#include<bits/stdc++.h>
using namespace std;
int n , m , ans = -0x7fffffff;
int a[200009] = {};
// vector<int> change2(int a){
//     vector<int> v;
//     while(a > 0){
//         v.push_back(a % 2);
//         a /= 2;
//     }
//     cout << a;
//     for(int i = 0;i < v.size();i++){
// 		cout << v[i] << " ";
// 	}
// 	cout << endl;
//     return v;
// }
// int and1(int a , int b){
//     int ans = 0;
//     vector<int> a1 , b1 , c1;
//     cout << '*' << a << endl;
//     a1 = change2(a);
//     b1 = change2(b);
//     for(int i = 0;i < min(a1.size() , b1.size());i++){
// 		//cout << a1[i] << " ";
//         if(a1[i] == 1 && b1[i] == 1){
//             c1.push_back(1);
//         }else{
//             c1.push_back(0);
//         }
//     }
//     for(int i = 0;i < c1.size();i++){
//         ans = ans * 2 + c1[i];
//     }
// }
// void dfs(int s , int now , int ss){
// 	if(now > n){
// 		return;
// 	}
//     s = and1(s , a[now]);
//     if(ss == m){
//         ans = max(ans , s);
//         return;
//     }
//     //cout << a[now] << a[now + 1] << s;
//     dfs(s , now + 1 , ss + 1);
// }
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    cout << a[n - m + 1];
    return 0;
}
