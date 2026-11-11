//什么你怎么知道我整个万圣节雀魂掉了600多分了
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200007],ans,mx=-1,mxv;
/*int popcount(int what){
    int ans=0;
    do{
        ans += what%2;
        what /= 2;
    }while(what);
    return ans;
}*/
int upperbit(int what){
    int p=0;
    while((1<<p)<=what)++p;
    return p;
}
void debug(){
    cout << "$$$";
    for(int i = 1;i <= n;++i){
        cout << a[i] << ' ';
    }
    cout << ", and 内容包含敏感词，建议检查后提交，如果确定提交请输入“确定提交”! ans=" << ans << endl;
}
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    while((1<<mxv)<mx)++mxv;
    int flag = 1;
    for(int i = mxv+1;i >= 0;--i){
        if(flag)sort(a+1,a+n+1,cmp);
        int j = 1;
        //debug();
        //cout << "i=" << i << ",upper=" << upperbit(a[j]) << endl;
        for(;upperbit(a[j])>=i&&j<=n;++j);
        --j;
        //cout << "j=" << j << endl;
        if(j >= m){//upperbit保住了
            n = j;
            ans += max(0,(1<<i-1));
            flag = 0;
        }else{
            flag = 1;
        }
        for(int k = 1;k <= j;++k)a[k]-=(1<<i-1);
    }
    cout << ans;
    return 0;
}

/*
闲来无事，随便统计一下。
代码长度（不计算本条注释）：1377B
字符统计（不计算所有注释和所有非ASCII字符）：
\n:46
(空格):292
!:1
":12
#:2
$:3
&:2
':2
(:23
):23
+:19
,:15
-:8
.:3
/:1
0:9
1:16
2:1
7:1
;:37
<:29
=:23
>:11
[:6
]:6
a:29
b:7
c:11
d:13
e:21
f:14
g:9
h:5
i:45
j:8
k:4
l:12
m:17
n:46
o:19
p:13
r:17
s:15
t:32
u:14
v:5
w:5
x:10
{:9
}:9
*/
