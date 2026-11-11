#include<cstdio>
int main(){
    int c1,c2,n1,n2;
    char s1[3],s2[3];
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%s%d%s",&c1,s1,&c2,s2);
    if(c1==c2){
        printf("1");
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            printf("1");
            if(s1[2]<='C')n1=1;
            else n1=0;
            if(s2[2]<='C')n2=1;
            else n2=0;
            if(n1==n2){
                printf("1");
                if((s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
                    printf("1");
                }else{
                    printf("0");
                }
            }else{
                printf("00");
            }
        }else{
            printf("000");
        }
    }else{
        printf("0000");
    }
    printf("\n");
    return 0;
}
/*
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"><!-- InstanceBegin template="/Templates/pages.dwt" codeOutsideHTMLIsLocked="false" -->
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta http-equiv="Pragma" content="no-cache" />
<meta http-equiv="Cache-Control" content="no-cache" />
<meta http-equiv="Expires" content="0" />
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<title>北京青少年信息学活动程序回收系统</title>
<link href="/css/bootstrap.min.css" rel="stylesheet" type="text/css" />
<link href="/css/font-awesome.min.css" rel="stylesheet" type="text/css" />
<link href="/css/styles.css" rel="stylesheet" type="text/css" />
<link href="/codemirror/codemirror.css" type="text/css" rel="stylesheet" />
<link href="/codemirror/theme/eclipse.css" type="text/css" rel="stylesheet" />
<link href="/codemirror/theme/neat.css" type="text/css" rel="stylesheet" />
<style>
.lq-langsel-btns .btn, .lq-oneeditor-btns .btn, .lq-multieditor-btns .btn {
	width:80px;
}
</style>
</head>

<body>

<div style="background-image:url(/img/head.png); height:84px; width:1200px; margin:0 auto; text-align:right;">
	<div style="padding: 16px;">
		<a class="btn btn-default" id="lq-logout-btn"></a>
	</div>
</div>
<div class="main-cont">
	<table>
		<tr><td width="267px" style="vertical-align: top;">
			<div class="menu-bar">
				<div>
					<div class="menu-item"><i class="fa fa-clock-o rspace"></i><span id="info4"></span></div>
					<div class="menu-item"><i class="fa fa-user rspace"></i><span class="info-user"></span></div>
					<a href="home.page" class="menu-item hv"><i class="fa fa-info-circle rspace"></i>考试须知</a>
					<a id="lq-cmd-prdown" href="#" class="menu-item"><i class="fa fa-download rspace"></i>试题下载</a>
					<a href="submits.page" class="menu-item hv active"><i class="fa fa-edit rspace"></i>答题</a>
					<a href="messages.page" class="menu-item hv"><span id="lq-msg-info"></span></a>
				</div>

			</div>
		</td><td style="vertical-align: top;">
			<div class="center-cont">
				<div style="width:600px; margin: 100px auto; ">
					<div id="lq-time-left"></div>
					<table class="table">
						<thead>
							<tr>
								<th style="width: 60px;">序号</th>
								<th>试题名称</th>
								<th style="width: 170px;">提交时间</th>
								<th style="width: 80px;">内容长度</th>
								<th style="width: 110px;">提交</th>
							</tr>
						</thead>
						<tbody class="lanqiao-prtable"></tbody>
					</table>
				</div>
			</div>
		</td></tr>
	</table>
</div>


<!-- Modal -->
<div class="modal fade" id="codePreviewer" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
	<div class="modal-dialog modal-lg">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
				<h4 class="modal-title" id="myModalLabel">查看答案</h4>
			</div>
			<table class="table kvtab">
				<tr><th width="76px">试题名称</th><td class="preview-prname"></td></tr>
				<tr><th>编译语言</th><td class="preview-lang"></td></tr>
				<tr><th>MD5</th><td class="preview-md5"></td></tr>
				<tr><th>源代码</th><td>
					<div class="main-editor">
						<textarea id="code-editor" class="form-control" rows="10"></textarea>
					</div>
					<div class="second-editor" style="display:none;">
						<textarea id="second-code-editor" class="form-control" rows="10"></textarea>
					</div>
				</td></tr>
			</table>
			<div class="modal-footer">
				<button id="lq-pr-close" type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
				<button id="lq-pr-submit" type="button" class="btn btn-primary"><i class="fa fa-edit"></i> 重新编辑</button>
			</div>
		</div><!-- /.modal-content -->
	</div><!-- /.modal-dialog -->
</div><!-- /.modal -->


<!-- Modal -->
<div class="modal fade" id="codeSubmitter" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
				<h4 class="modal-title" id="myModalLabel">答案提交</h4>
			</div>
			<div class="modal-body">
				<div><label class="modal-prname"></label></div>

				<div id="lq-langsel">
					<div class="lanqiao-ref"><label><span>编译语言</span></label></div>
					<div class="well">
						<div class="btn-group lq-langsel-btns">
							<a id="labelc" href="###" class="btn btn-default optionc" style="display:none;">C</a>
							<a id="labelcpp" href="###" class="btn btn-default optioncpp" style="display:none;">C++</a>
						</div>
					</div>
				</div>

				<div id="lq-codeeditor">
					<div class="lanqiao-ref"><label>源代码</label></div>
					<div class="well lanqiao-no-bottom-margin plain-editor">
						<textarea id="plain-code-editor" class="form-control" rows="10"></textarea>
					</div>
					<span class="help-block">答案可多次提交，以最后一次为准。</span>
					<span class="help-block">请输入完整的代码。建议在本地的软件中编辑调试好后粘贴到这里，建议不要在此修改代码。在这里修改代码可能因为网络原因丢失代码，由此产生的后果自行承担。</span>
					<span class="help-block">答案不能超过 <b>100KB</b> ，否则无法提交。</span>
				</div>

			</div>
			<div class="modal-footer">
				<button id="lq-sb-close" type="button" class="btn btn-default" data-dismiss="modal">取消</button>
				<button id="lq-sb-submit" type="button" class="btn btn-primary"><i class="fa fa-check"></i> 提交</button>
			</div>
		</div><!-- /.modal-content -->
	</div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<script type="text/javascript" src="codemirror/codemirror.min.js"></script>
<script src="/codemirror/clike/clike.js"></script>
<script src="/codemirror/python/python.js"></script>
<script src="/codemirror/addon/selection/active-line.js"></script>
<script src="/codemirror/addon/edit/matchbrackets.js"></script>
<script src="/js/submits.js"></script>

<script type="text/javascript">
var checkIntervalVal, isStarted = false;
function checkStart() {
	$.post("/user.CheckStarted.dt", {}, function(obj) {
		if (obj["rets"]=="STARTED")
		{
			if (checkIntervalVal)
				clearInterval(checkIntervalVal);
			isStarted = true;
			currentInfo.timec = new Date().getTime();
			currentInfo.timeleft = obj.timeleft;
			currentInfo.timepast = obj.timepast;
			currentInfo.extratime = obj.extratime;
			setScheduleLeft(0);
			$("#lq-cmd-prdown").addClass('hv');
			$("#lq-cmd-prdown").attr("disabled", false);
			$("#lq-cmd-submit").attr("disabled", false).click(function() {
				location.href = "/submits.page";
			});
		}
		if (obj["rets"]=="SCHEDULED")
		{
			setScheduleLeft(parseInt(obj.scheduledleft));
		}
	}, "json");
}

function onPageReadyDong()
{
	$('.info-user').text(currentInfo.name);

	$('.lq-langsel-btns .btn').click(radioBtn);

	showMySubmits();

	var ustu = currentInfo["ustatus"];
	var hasUser = !(!ustu || ustu=="" || ustu=="null");
	if (hasUser && ustu!="wait")
	{
		$("#lq-cmd-prdown").attr("disabled", false).click(function() {
			$("#dframe").attr("src", "/problem.DownloadProblemFile.do?pid=1&rand=" + Math.random());
		});
		$("#lq-cmd-submit").attr("disabled", false).click(function() {
			location.href = "/submits.page";
		});
	}
	else
	{
		var tHtml = "<br /><i class='fa fa-angle-right'></i> 比赛未开始";
		$("#lq-cmd-prdown").find("small").html(tHtml);
		$("#lq-cmd-submit").find("small").html(tHtml);
	}

	checkStart();
	checkIntervalVal = setInterval(checkStart, 3000);
	checkMessage();
	setInterval(checkMessage, 3000);

	if (createCodeMirrorEditor)
		createCodeMirrorEditor();
}
</script>

<iframe id="dframe" src="about:blank" style="width:1px; height:1px; visibility:hidden; border:0px; padding:0px; margin:0px;"></iframe>
<script src="/js/jquery.min.js" type="text/javascript"></script>
<script src="/js/bootstrap.min.js" type="text/javascript"></script>
<script src="/js/common.js" type="text/javascript"></script>
<script type="text/javascript">
	var showLoginIfNoUser = true;
	function getCurrentInfo()
	{
		var ret = {"alertinfo0":"离比赛结束还剩不到十分钟时间。","alertinfo1":"离比赛结束还剩不到30分钟时间。","alerttime0":"600","alerttime1":"1800","cdate":"2026年10月31日 星期六","extratime":"no","groupid":"入门级","groupname":"CSPJ2026（?）","idnumber":"?","name":"?","notuserdisplay":"none","regionname":"","ret":"1","roomid":"?","roomname":"","serverdate":"2026年10月31日","servertime":"40151","time":"40151","timeleft":"3049","timepast":"11350","userdisplay":"block","userid":"?","ustatus":"normal"};
		ret.timec = new Date().getTime();
		return ret;
	}
	var currentInfo = getCurrentInfo();
	$(document).ready(function(e){
		onPageReady(currentInfo, showLoginIfNoUser);
		onPageReadyDong();
	});
</script>
</body>
<!-- InstanceEnd --></html>
*/
