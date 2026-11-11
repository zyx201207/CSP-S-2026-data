#include<bits/stdc++.h>
using namespace std;
int a[500000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    greater<int> g;
    sort(a+1,a+1+n,g);
    cout<<a[m];
}
/*
【题目描述】
小 R 有 n 个非负整数 a 1 , a 2 , . . . , a n 。
小 X 给了小 R 一个正整数 m,并要求小 R 从这 n 个非负整数中选出 恰
. 好
. m 个,
. 按
. 位
. 与的值最大。
.
你需要帮助小 R 求出,他能选出的 m 个数的按位与的最大值。
【输入格式】
从文件 and.in 中读入数据。
输入的第一行包含两个正整数 n, m。
输入的第二行包含 n 个非负整数 a 1 , a 2 , . . . , a n ,依次表示小 R 的 n 个非负整数。
【输出格式】
输出到文件 and.out 中。
输出一行一个非负整数,表示小 R 能选出的 m 个数的按位与的最大值。
【样例 1 输入】
1 4 2
2 3 15 12 12
【样例 1 输出】
1
12*/